/*

Program an iterator for a List which may include nodes or List, i.e., {0,
{1,2}, 3 ,{4,{5, 6}}} Iterator returns 0 - 1 - 2 - 3 - 4 - 5 - 6.

*/


class Collection {
public:
        T next() {
            
            if (_type == 0)
            {
                if (_index == 0)
                {
                    _index++;
                    return _value
                }
                else
                {
                    throw Exception;
                }
            }
            else
            {
                while (_index < _buckets.size()) {
                    if (_buckets[_index].hasNext())
                        return _buckets[_index].next();
                    _index++;
                }
                throw Exception;
            }
        }
        
        bool hasNext() {
            if (_type == 0) {
                // because we have only one value
                // the index is initialized to zero at first
                if (_index == 0)
                    return true;
                else
                    return false;
            } else {
                    int tmp = _index;
                    // in case we have empty buckets[_index], so we should loop over it
                    while (tmp < _buckets.size())
                    {
                        if (_buckets[tmp].hasNext())
                            return true;
                        tmp++;
                    }
                    if (tmp == _buckets.size())
                        return false;  // all the buckets are used
            }
        }

private:
        std::vector<Collection> _buckets;
        T _value;
        int _type; // 0: value 1: buckets
        int _index; // the current iterator position in buckets, or the value is used or not
};
