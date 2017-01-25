#pragma once


namespace Eegeo
{
    class AllocHelper
    {
    public:

        AllocHelper(const char* type, const char* file, int line, int elementCount = -1) :
            m_type(type),
            m_file(file),
            m_line(line),
            m_elementCount(elementCount)
        {
        }

        template <class T>
        T* operator << (T* rhs)
        {
            AnnotateAllocation(rhs);

            return rhs;
        }

    private:
        
        void AnnotateAllocation(void*);

        const char* m_type;
        const char* m_file;
        int m_line;
        int m_elementCount;
    };
};