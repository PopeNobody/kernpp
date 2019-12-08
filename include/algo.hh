#ifndef algo_hh
#define algo_hh algo_hh

template<typename ii_t, typename oi_t>
oi_t copy(ii_t b, ii_t e, oi_t d)
{
	while(b!=e)
		*d++=*b++;
	return d;
}


#endif
