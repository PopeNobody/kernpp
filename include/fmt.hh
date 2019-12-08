#ifndef fmt_hh
#define fmt_hh

namespace num_fmt
{
	inline char hex_dig(int val) {
		static char digs[]="0123456789abcdef";
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
};

#endif
