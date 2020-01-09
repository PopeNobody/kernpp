#ifndef fmt_hh
#define fmt_hh

#if 0
#define AAI __attribute__ ((__always_inline__))
#else
#define AAI
#endif

typedef unsigned fd_t;
namespace fmt
{
	//inline char hex_dig(int val) AAI;
	static char hex_dig(int val) {
		constexpr char digs[]="0123456789abcdef";
		return digs[val&0xf];
	};
	inline char *fmt_hex(unsigned long val, char *beg, char *end)
	{
		for(int i=0;i<2*sizeof(val);i++){
			*--end=hex_dig(val);
			val/=0x10;
		};
		return end;
	};
	inline char *fmt_ptr(void *val, char *beg, char *end) {
		*--end=']';
		end=fmt_hex(size_t(val),beg,end);
		*--end='x';
		*--end='0';
		*--end='[';
		return end;
	};
	inline char *fmt_dec(unsigned long val, char *beg, char *end, int width=0)
	{
		char *max=(width?end-width:0);
		if(val) {
			while(val) {
				*--end=hex_dig(val%10);
				val/=10;
			};
		}else{
			*--end='0';
		};
		if(max)
			while(end>max)
				*--end=' ';
		return end;
	};
        using namespace sys;
	inline int write_dec(fd_t fd, size_t val) {
		char buf[sizeof(val)*4];
		return write(fd, fmt::fmt_dec(val,buf,&buf[sizeof(buf)-1]));
	};
	inline int write_hex(fd_t fd, size_t hex) {
		char buf[sizeof(hex)*4];
		return write(fd, fmt::fmt_hex(hex,buf,&buf[sizeof(buf)-1]));
	};
	inline int write_ptr(fd_t fd, void *ptr) {
		char buf[sizeof(ptr)*4];
		return write(fd, fmt::fmt_ptr((void*)ptr,buf,&buf[sizeof(buf)-1]));
	};
	inline int write_tm(fd_t fd, timeval &tm) {
		char buf[(sizeof(tm.tv_sec)+sizeof(tm.tv_nsec))*4+16];
		char * const end=&buf[sizeof(buf)-1];
		char *pos=end;
		*--pos='}';
		pos=fmt::fmt_dec(tm.tv_nsec,buf,pos);
		*--pos=',';
		pos=fmt::fmt_dec(tm.tv_sec,buf,pos);
		*--pos='{';
		return write(fd,pos,end);
	};
	inline int write_tm(fd_t fd, timespec &tm) {
		char buf[(sizeof(tm.tv_sec)+sizeof(tm.tv_nsec))*4+16];
		char * const end=&buf[sizeof(buf)-1];
		char *pos=end;
		*--pos='}';
		pos=fmt::fmt_dec(tm.tv_nsec,buf,pos);
		*--pos=',';
		pos=fmt::fmt_dec(tm.tv_sec,buf,pos);
		*--pos='{';
		return write(fd,pos,end);
	};

        // This doesn't even format, it parses.  But here it is.
        inline int atoi(const char *a) {
          int i=0;
          char ch;
          while(ch=*a++) {
            switch(ch) {
              case '1': case '2': case '3': case '4': case '5':
              case '6': case '7': case '8': case '9': case '0':
                i*=10;
                i+=(ch-'0');
                break;
              default:
                write(2,"err!");
                exit(1);
            };
          };
          return i;
        };

#define show_val(x) do{ \
  write(2,L(#x " => ")); \
  write_dec(2,(x)); \
  write(2,L("\n")); \
}  while(false);
};
#undef AAI

#endif
