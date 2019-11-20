#pragma once

/*-----------------------------------
Overloaded constructor     |X|
Copy constructor           |X|
Move constructor           |X|
Destructor				   |X|
Assignment operator		   |X|
Move assignment operator   |X|
pointer operator(->)	   |X|
dereference operator(*)	   |X|
get method				   |X|
use_count				   |X|
-------------------------------------
*/

namespace usu
{
    template <typename T>
    class shared_ptr
    {
      public:
        shared_ptr()
        {
            m_dataptr = nullptr;
            m_count = 0;
        }

        shared_ptr(T* ptr)
        {
            m_dataptr = ptr;
            m_count = 1;
        }

        shared_ptr(shared_ptr<T>& ptr)
        {
            m_dataptr = ptr.m_dataptr;
            m_count++;
        }

        shared_ptr(shared_ptr<T>&& ptr)
        {
            m_dataptr = ptr.m_dataptr;
        }

        ~shared_ptr()
        {
            if (this.count == 0)
            {
                delete m_dataptr;
            }
        }

        T* operator=(shared_ptr& ptr)
        {
            m_dataptr = ptr.m_dataptr;
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

        T* operator->()
        {
            return this->m_dataptr;
        }

        T& operator*()
        {
            return *m_dataptr;
        }

        int use_count()
        {
            return m_count;
        }

        T* get()
        {
            return m_dataptr;
        }

      private:
        T* m_dataptr;
        int m_count;
    };

    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename T>
    class shared_ptr<T[]>
    {
      public:
        shared_ptr()
        {
            m_dataptr = nullptr;
            size = 0;
            m_count = 0;
		}

        shared_ptr(T* ptr, std::size_t sz)
        {
            m_dataptr = ptr;
            size = sz;
        }

		shared_ptr(shared_ptr<T>& ptr)
        {
            m_dataptr = ptr.m_dataptr;
            m_count++;
        }

        shared_ptr(shared_ptr<T>&& ptr)
        {
            m_dataptr = ptr.m_dataptr;
        }

        ~shared_ptr()
        {
            if (this.count == 0)
            {
                delete m_dataptr[];
            }
        }

      private:
        T* m_dataptr;
        std::size_t size;
        int m_count;
    };

    template <typename T, unsigned int N>
    shared_ptr<T[]> make_shared_array()
    {
        return shared_ptr<T[]>(new T[N], N);
    }
} // namespace usu