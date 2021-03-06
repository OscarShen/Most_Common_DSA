# Vector

Vector是一种非常非常非常常用的线性表数据结构！理解Vector的动态扩容是理解C++标准库中std::vector实现的关键！

## 理解向量

首先我们需要理解什么是一个向量：

向量就是线性数组的一种抽象与泛化，它也是由具有线性次序的一组元素构成的集合，其中的元素分别由秩相互区分。

向量访问元素的方式称为“循秩访问”。

## 实现向量

库中Vector的实现采用了类模板，以使我们的Vector可以容纳各种类型；

内存分配采用了allocator类，它可以使内存的分配和对象的构造分离开来，这在像Vector这种需要动态分配内存的容器中是一个十分有用的特性，
该特性可以避免无意义的对象构造产生的浪费！

## 学习参考

关于向量的原理可以参考清华邓俊辉的《数据结构（C++语言版）》第二章；

关于allocator类可以参考C++Primer（中文版） p427页