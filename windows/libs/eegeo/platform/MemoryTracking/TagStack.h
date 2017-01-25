#pragma once

// simple in-place stack designed to avoid allocations (as it is used inside the memory allocation debugging).
// See the comment on https://github.com/eegeo/eegeo-mobile/commit/e31e67e0da5f46043d33366dbe73e7b92dcec8c5 for a discussion
// of why this isn't an STL stack.
template <int TMaxDepth>
class TagStack
{
public:

    TagStack() :
        m_currentIndex(0)
    {
        m_tags[0] = "";
    }

    void PushTag(const char* tag) { m_tags[++m_currentIndex] = tag; }
    void PopTag() { --m_currentIndex; }
    const char* Peek() const { return m_tags[m_currentIndex]; }

private:

    int m_currentIndex;
    const char* m_tags[TMaxDepth];
};

