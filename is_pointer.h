 #ifndef IS_POINTER_H
 #define IS_POINTER_H
 
 namespace std{
	template <typename T>
	struct remove_const
	{
		typedef T type;
	};

	template <typename T>
	struct remove_const<const T>
	{
		typedef T type;
	};

	template <typename T>
	struct remove_volatile
	{
		typedef T type;
	};

	template <typename T>
	struct remove_volatile<volatile T>
	{
		typedef T type;
	};

	template <typename T>
	struct remove_cv : remove_const<typename remove_volatile<T>::type> {};

	template <typename T>
	struct is_unqualified_pointer
	{
		enum { value = false };
	};

	template <typename T>
	struct is_unqualified_pointer<T*>
	{
		enum { value = true };
	};

	template <typename T>
	struct is_pointer_type : is_unqualified_pointer<typename remove_cv<T>::type> {};

	template <typename T>
	bool is_pointer(const T&)
	{
		return is_pointer_type<T>::value;
	}
 }
 #endif // IS_POINTER_H