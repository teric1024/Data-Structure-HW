## Notes

- [const for function](http://welkinchen.pixnet.net/blog/post/48176548-const-%E5%9C%A8%E6%88%90%E5%93%A1%E5%87%BD%E5%BC%8F%E4%B8%AD%E7%9A%84%E7%94%A8%E6%B3%95)
- [how to check the type of variable](https://en.cppreference.com/w/cpp/language/typeid)
- [how to get IEEE for double](https://stackoverflow.com/questions/34796424/convert-a-double-to-int-using-union)


## BUG log
1. wrong type transfer
- **Error Message**
D:\Eric-HD\college\107-1\資料結構\homework\Data-Structure-HW\hw4\hw4\Entry.h|24|error: binding 'CheckerBoard* const' to reference of type 'CheckerBoard*&' discards qualifiers|
    - ![](https://i.imgur.com/LZvjS2P.png)
    - ![](https://i.imgur.com/MC8LMbA.png)
- **Solution**
//write solution here
2. cannot use function newNode with typename
- **Error Message**
D:\Eric-HD\college\107-1\資料結構\homework\Data-Structure-HW\hw4\hw4\DoublyLinkedList\DList.cpp|57|error: no matching function for call to 'Entry<CheckerBoard*, Integer*>::Entry()'|
    -![](https://i.imgur.com/AIqLLhL.png)
