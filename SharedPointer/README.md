# Custom implementation of shared_ptr class

# Output
```
Using stl shared_ptr
Integer constructor, val: 10
shared_ptr ptr2 use count: 2, addr: 0x1d11030, val: 10
shared_ptr ptr3 use count: 2, addr: 0x1d11030, val: 10
shared_ptr ptr4 use count: 1, addr: 0x1d11070, val: 1, 2, 3, 4, 5, 
Integer constructor, val: 500
shared_ptr ptr5 use count: 1, addr: 0x1d110b0, val: 500
Integer destructor, val: 500
Integer destructor, val: 10
Using Custom SharedPointer
Integer constructor, val: 10
SharedPointer constructor, ref count1
SharedPointer copy constructor, ref count2
SharedPointer ptr2 use count: 2, addr: 0x1d11050, val: 10
SharedPointer move constructor, ref count2
SharedPointer ptr3 use count: 2, addr: 0x1d11050, val: 10
SharedPointer constructor, ref count1
SharedPointer ptr4 use count: 1, addr: 0x1d11090, val: 1, 2, 3, 4, 5, 
Integer constructor, val: 500
SharedPointer constructor, ref count1
SharedPointer ptr5 use count: 1, addr: 0x1d110d0, val: 500
SharedPointer destructor: ref_count 1
Ref count is 0, deallocating object 0x1d110d0
Calling delete
Integer destructor, val: 500
SharedPointer destructor: ref_count 1
Ref count is 0, deallocating object 0x1d11090
Calling delete []
SharedPointer destructor: ref_count 2
SharedPointer destructor: ref_count 1
Ref count is 0, deallocating object 0x1d11050
Calling delete
Integer destructor, val: 10
Ending 

```
