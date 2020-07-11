#include<exception>
#include<typeinfo>
#include<typeindex>
#include<iostream>
//1
class exception
{
public:

	exception() noexcept
		: _Data()
	{
	}

	explicit exception(char const* const _Message) noexcept
		: _Data()
	{
		__std_exception_data _InitData = { _Message, true };
		__std_exception_copy(&_InitData, &_Data);
	}

	exception(char const* const _Message, int) noexcept
		: _Data()
	{
		_Data._What = _Message;
	}

	exception(exception const& _Other) noexcept
		: _Data()
	{
		__std_exception_copy(&_Other._Data, &_Data);
	}

	exception& operator=(exception const& _Other) noexcept
	{
		if (this == &_Other)
		{
			return *this;
		}

		__std_exception_destroy(&_Data);
		__std_exception_copy(&_Other._Data, &_Data);
		return *this;
	}

	virtual ~exception() noexcept
	{
		__std_exception_destroy(&_Data);
	}

	virtual char const* what() const
	{
		return _Data._What ? _Data._What : "Unknown exception";
	}

private:

	__std_exception_data _Data;
};

class bad_exception
	: public exception
{
public:

	bad_exception() noexcept
		: exception("bad exception", 1)
	{
	}
};

class bad_alloc
	: public exception
{
public:

	bad_alloc() noexcept
		: exception("bad allocation", 1)
	{
	}

private:

	friend class bad_array_new_length;

	bad_alloc(char const* const _Message) noexcept
		: exception(_Message, 1)
	{
	}
};

class bad_array_new_length
	: public bad_alloc
{
public:

	bad_array_new_length() noexcept
		: bad_alloc("bad array new length")
	{
	}
};
//2
class _CRTIMP2_IMPORT bad_cast : public exception { // base of all bad cast exceptions
public:
	bad_cast(const char* _Message = "bad cast") noexcept : exception(_Message) { // construct from message string
	}

	virtual ~bad_cast() noexcept { // destroy the object
	}

protected:
	virtual void _Doraise() const { // perform class-specific exception handling
		_RAISE(*this);
	}
};

// CLASS bad_typeid
class _CRTIMP2_IMPORT bad_typeid : public exception { // base of all bad typeid exceptions
public:
	bad_typeid(const char* _Message = "bad typeid") noexcept : exception(_Message) { // construct from message string
	}

	virtual ~bad_typeid() noexcept { // destroy the object
	}

protected:
	virtual void _Doraise() const { // perform class-specific exception handling
		_RAISE(*this);
	}
};

class _CRTIMP2_IMPORT __non_rtti_object : public bad_typeid { // report a non RTTI object
public:
	__non_rtti_object(const char* _Message) : bad_typeid(_Message) { // construct from message string
	}
};
//3
_CRT_BEGIN_C_HEADER

struct __std_type_info_data
{
	const char* _UndecoratedName;
	const char   _DecoratedName[1];
	__std_type_info_data() = delete;
	__std_type_info_data(const __std_type_info_data&) = delete;
	__std_type_info_data(__std_type_info_data&&) = delete;

	__std_type_info_data& operator=(const __std_type_info_data&) = delete;
	__std_type_info_data& operator=(__std_type_info_data&&) = delete;
};

_VCRTIMP int __cdecl __std_type_info_compare(
	_In_ const __std_type_info_data* _Lhs,
	_In_ const __std_type_info_data* _Rhs
);

_VCRTIMP size_t __cdecl __std_type_info_hash(
	_In_ const __std_type_info_data* _Data
);

_VCRTIMP const char* __cdecl __std_type_info_name(
	_Inout_ __std_type_info_data* _Data,
	_Inout_ __type_info_node* _RootNode
);

_CRT_END_C_HEADER
class type_info
{
public:

	type_info(const type_info&) = delete;
	type_info& operator=(const type_info&) = delete;

	size_t hash_code() const noexcept
	{
		return __std_type_info_hash(&_Data);
	}

	bool operator==(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) == 0;
	}

	bool operator!=(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) != 0;
	}

	bool before(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) < 0;
	}

	const char* name() const noexcept
	{
#ifdef _M_CEE_PURE
		return __std_type_info_name(&_Data, static_cast<__type_info_node*>(__type_info_root_node.ToPointer()));
#else
		return __std_type_info_name(&_Data, &__type_info_root_node);
#endif
	}

	const char* raw_name() const noexcept
	{
		return _Data._DecoratedName;
	}

	virtual ~type_info() noexcept;

private:

	mutable __std_type_info_data _Data;
};
//4.
_Check_return_opt_
__inline int __cdecl printf(
	_In_z_ _Printf_format_string_ char const* const _Format,
	...)
#if defined _NO_CRT_STDIO_INLINE
	;
#else
{
	int _Result;
	va_list _ArgList;
	__crt_va_start(_ArgList, _Format);
	_Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);
	__crt_va_end(_ArgList);
	return _Result;
}
#endif
