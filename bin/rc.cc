#include <syscall.hh>
#include <new.hh>
#include <rc.hh>
#include <stream.hh>


class TestObj {
	class body_t : public rc::body_t
	{
		public:
		body_t()
		{
		};
		~body_t()
		{
		}
		body_t(const body_t &rhs)
		{
		}
	};
	rc::hand_t<body_t> body;
	public:
	TestObj()
		: body(new body_t)
	{
	}
};
void test_it() {
	TestObj obj;
};

int main()
{
	stream::fdbuf_t stdout(1);
	stdout.put("test\n");
	stdout.put(__PRETTY_FUNCTION__).put("\n");
	test_it();
	return 0;
}

