#ifndef fmt_hh
#define fmt_hh

namespace fmt
{
	inline char hex_dig(int val) AAI;
	inline char hex_dig(int val) {
		char digs[]="0123456789abcdef";
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
	inline char *fmt_dec(unsigned long val, char *beg, char *end)
	{
		if(val) {
			while(val) {
				*--end=hex_dig(val%10);
				val/=10;
			};
		}else{
			*--end='0';
		};
		return end;
	};
};

#endif
