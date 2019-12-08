#ifndef rc_hh
#define rc_hh rc_hh

namespace rc {

	class body_t {                       
		public:                             
			void addReference();
			void removeReference();
			void markUnshareable();
			bool isShareable() const;
			bool isShared() const;

		protected:
			body_t();
			body_t(const body_t& rhs);
			body_t& operator=(const body_t& rhs);
			virtual ~body_t() = 0;

		private:
			int refCount;
			bool shareable;
	};
	template<class T>
		class hand_t {   
			public:      
				hand_t(T* realPtr = 0)
					: pointee(realPtr)
				{
					init();
				}
				hand_t(const hand_t& rhs)
					: pointee(rhs.pointee)
				{ 
					init();
				}
				~hand_t()
				{
					if (pointee)
						pointee->removeReference();
				}
				hand_t& operator=(const hand_t& rhs)
				{
					if (pointee == rhs.pointee)
						return *this;

					T *oldPointee = pointee;  
					pointee = rhs.pointee;
					init(); 

					if (oldPointee)
						oldPointee->removeReference();                

					return *this;
				}
				T* operator->() const
				{
					return pointee;
				}
				T& operator*() const
				{
					return *pointee;
				};

			private:
				T *pointee;
				void init() {
					if (pointee == 0) return;

					// This is going to slice objects if used
					// with a polymorphic type
					if (pointee->isShareable() == false) {
						pointee = new T(*pointee);
					}

					pointee->addReference();
				}
		};
};
 
 
#endif 
