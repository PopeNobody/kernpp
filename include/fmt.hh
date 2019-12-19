#ifndef fmt_hh
#define fmt_hh

#if 1
#define AAI __attribute__ ((__always_inline__))
#else
#define AAI
#endif

namespace fmt
{
	inline char hex_dig(int val) AAI;
	inline char hex_dig(int val) {
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
		end=fmt_hex(size_t(val),beg,end);
		*--end='x';
		*--end='0';
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
};
#undef AAI

#endif
