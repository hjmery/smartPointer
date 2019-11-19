#pragma once

/*
--------------------------------------------------------------
Overloaded constructor     |X|
Copy constructor           |X|
Move constructor           ||
Destructor				   ||
Assignment operator		   ||
Move assignment operator   ||
pointer operator(->)	   ||
dereference operator(*)	   ||
get method				   ||
use_count				   ||
--------------------------------------------------------------
*/

namespace usu
{
	template <typename T>
    class shared_ptr
    {
      public:
		shared_ptr(T* ptr) {
            m_dataptr = ptr;
		}
		shared_ptr(shared_ptr<T>& ptr) {
            m_dataptr = ptr.m_dataptr;
		}

	  private:
        T* m_dataptr;

	
	};
}