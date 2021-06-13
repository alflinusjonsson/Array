#pragma once

template<typename Array>
class ArrayIterator {
public:
	using ValueType = typename Array::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
public:
	ArrayIterator(PointerType ptr)
		: m_Ptr(ptr) {}

	ArrayIterator& operator++() {
		m_Ptr++;
		return *this;
	}

	ArrayIterator operator++(int) {
		ArrayIterator iterator = *this;
		++(*this);
		return iterator;
	}

	ArrayIterator& operator--() {
		m_Ptr--;
		return *this;
	}

	ArrayIterator operator--(int) {
		ArrayIterator iterator = *this;
		--(*this);
		return iterator;
	}

	ReferenceType operator[](int index) {
		return *(m_Ptr + index);
	}

	PointerType operator-> () {
		return m_Ptr;
	}

	ReferenceType operator* () {
		return *m_Ptr;
	}

	bool operator==(const ArrayIterator& other) const {
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const ArrayIterator& other) const {
		return !(*this == other);
	}

private:
	PointerType m_Ptr;
};

template<typename T, size_t S>
class Array
{
public:
	using ValueType = T;
	using Iterator = ArrayIterator<Array<T, S>>;
public:
	constexpr size_t Size() const { return S; }

	T& operator[](size_t index) { return m_Data[index]; }

	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }

	const T* Data() const { return m_Data; }

	Iterator begin() { return Iterator(m_Data); }

	Iterator end() { return Iterator(m_Data + S); }
private:
	T m_Data[S];
};

/*
* Initiate int array using for example:
* 	int size = 5;
*	Array<int, size> values;
*/