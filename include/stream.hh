#ifndef stream_hh
#define stream_hh stream_hh

#include <syscall.hh>

namespace stream
{
	namespace util {
		static const char *strend(const char *b){
			while(*b)
				++b;
			return b;
		};
	};
	using namespace util;
	class str_t {
		const char *_beg;
		const char *_end;
		public:
		str_t(const char *beg, const char *end)
			:_beg(beg), _end(end)
		{
		};
		str_t(const char *beg)
			:_beg(beg), _end(strend(beg))
		{
		};
		str_t(const char *beg, size_t len)
			:_beg(beg), _end(beg+len)
		{
		};
		const char *beg() const{
			return _beg;
		};
		const char *end() const {
			return _end;
		};
	};
	class buf_t
	{
		public:
		struct putter_t {
			buf_t &owner;
			putter_t(buf_t &owner)
				:owner(owner)
			{
			};
			putter_t() = delete;
			putter_t(const putter_t &) = delete;
			putter_t &operator=(const putter_t &)=delete;
			putter_t &put(str_t str)
			{
				owner.put(str);
				return *this;
			}
		};
		putter_t &put(const str_t &str)
		{
			__write(str);
			return _putter;
		};
		template<typename a1_t, typename a2_t>
			putter_t &put(a1_t a1, a2_t a2) {
				put(str_t(a1,a2));
				return _putter;
			};
		putter_t &put(const char *b)
		{
			put(b,strend(b));
			return _putter;
		};
		protected:
			buf_t();
			virtual void __write(const str_t &str)=0;
		private:
		putter_t _putter;
	};
	class fdbuf_t : public buf_t
 	{
		fd_t fd;
		protected:

		virtual void __write(const str_t &str);
		public:
		fdbuf_t(fd_t fd)
			: fd(fd)
		{
			put("fdbuf_t::fdbuf_t\n");
		}
		~fdbuf_t()
		{
		};
	};
};
#endif
