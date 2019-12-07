
#if 0
	static char hex_dig(int val) {
		static char digs[]="0123456789abcdef";
		return digs[val&0xf];
	};
	buf_t &app(const char *beg, const char *end){
		while(beg!=end) {
			if(!room())
				flush();
			text[pos++]=*beg++;
			text[pos]=0;
		};
		return *this;
	};
	buf_t &pad(size_t n, const char *beg, size_t l)
 	{
		app(beg,beg+l);
		while(n>l){
			static char space[]=" ";
			app(space,space+1);
			--n;
		};
		return *this;
	};
	buf_t &pad(size_t n, const char *beg)
	{
		return pad(n,beg,strlen(beg));
	};
	buf_t &app(char ch) {
		return app(&ch,1+&ch);
	};
	buf_t &app(const char *beg, size_t len) {
		return app(beg,beg+len);
	};
	buf_t &app(const char *beg) {
		return app(beg,strlen(beg));
	};
	buf_t &app(size_t val, bool neg=false) {
		char buf[sizeof(val)*3+2];
		int end=sizeof(buf);
		int pos=end;
		buf[--pos]=0;
		if(val) {
			while(val) {
				buf[--pos]=hex_dig(val%10);
				val/=10;
			};
		} else {
			buf[--pos]='0';
		};
		if(neg){
			buf[--pos]='-';
		};
		return app(buf+pos,buf+end);
	};
	buf_t &app(void *ptr) {
		size_t val=size_t(ptr);
		char buf[sizeof(ptr)*2+4];
		int pos=sizeof(buf);
		buf[--pos]=0;
		for(int i=0;i<sizeof(ptr);i++){
			buf[--pos]=hex_dig(val);
			buf[--pos]=hex_dig(val>>4);
			val=val/0x100;
		};
		buf[--pos]='x';
		buf[--pos]='0';
		return app(buf+pos,buf+sizeof(buf));
	};
	buf_t &app(int val) {
		if(val<0)
			return app(-val,true);
		else
			return app(val,false);
	};
#endif
