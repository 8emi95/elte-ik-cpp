#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <iostream>
#include <list>
#include <algorithm>

template <typename Cont, typename CharT = typename Cont::value_type>
class line_editor
{
    std::list<CharT> line;
    typename std::list<CharT>::iterator cursor;
    bool insert_mode;

  public:
    template <class T, class U>
    friend class line_editor;

    line_editor() : cursor(line.end()), insert_mode(false) {}

    void press(CharT c)
    {
        if (insert_mode && cursor != line.end())
            *cursor = c;
        else
            cursor = line.insert(cursor, c);

        cursor++;
    }

    void home()
    {
        cursor = line.begin();
    }

    Cont enter()
    {
        Cont ret(line.begin(), line.end());
        line.clear();
        cursor = line.end();
        return ret;
    }

    void insert()
    {
        insert_mode = !insert_mode;
    }

    void del()
    {
        if (cursor != line.end())
            cursor = line.erase(cursor);
    }

    void backspace()
    {
        if (cursor != line.begin())
        {
            cursor--;
            del();
        }
    }

    template <typename T, typename E>
    void swap(line_editor<T, E> &other)
    {
        std::swap(line, other.line);
        std::swap(insert_mode, other.insert_mode);
        std::swap(cursor, other.cursor);
    }
};

#endif //LINEEDIT_H