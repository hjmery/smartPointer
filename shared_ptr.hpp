#pragma once

/*
--------------------------------------------------------------
Overloaded constructor     |X|
Copy constructor           |X|
Move constructor           |X|
Destructor				   |X|
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
		shared_ptr(T* ptr) 
		{
            m_dataptr = ptr;
		}

		shared_ptr(shared_ptr<T>& ptr) {
            m_dataptr = ptr.m_dataptr;
		}

        shared_ptr(shared_ptr<T>&& ptr)
        {
            m_dataptr = ptr.m_dataptr;
        }

		~shared_ptr() 
		{
            delete m_dataptr;
		}

		shared_ptr& operator=(shared_ptr&& ptr) 
		{
            if (this != &ptr)
            {
                delete[] m_dataptr;
			}
            m_dataptr = ptr.m_dataptr;
            ptr.m_dataptr = nullptr;
            return *this;
		}

	  private:
        T* m_dataptr;

	
	};
}