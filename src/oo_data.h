#ifndef OO_DATA_H
#define OO_DATA_H


#include "oo_amxx.h"



namespace oo
{
	/*
	*	Class (belongs to a plugin):
	*		[Parent class]
	*		
	*		Constructor IDs
	*		| Constructor names
	*		| Constructor argument lists
	*		
	*		Destructor
	*		
	*		
	*		Method IDs
	*		| Method names
	*		| Method argument lists
	*		
	*		Member IDs
	*		| Member names
	*		| Member data types
	*		| Member sizes
	* 
	*	Object:
	*		Class
	*		Member data
	* 
	*/
	struct ConstructorArrays
	{

	};


	using MethodID = uint32_t;
	using MemberID = uint32_t;

	using ClassID = uint32_t;
	constexpr const ClassID CLASS_NULL = 0u;

	struct ClassArrays
	{
		struct
		{
			using StrPos = uint32_t;
			std::vector<char>	pool;	// e.g. "CAnimal\0CBird\0CDog...\0"
			std::vector<StrPos>	strpos;
		} class_names;

		std::vector<int> plugin_ids;

		std::vector<int> destructors;

		std::vector<MethodID> methodIDs;


		inline ClassID FindClassIdByName(std::string_view class_name)
		{
			const char* pfound = std::strstr(class_names.pool.data(), class_name);
			if (pfound == nullptr)
				return CLASS_NULL;
			ClassID strpos = static_cast<ClassID>(pfound - class_names.pool.data());
			auto iter = std::find(class_names.strpos.cbegin(), class_names.strpos.cend(), strpos);
			assert(iter == class_names.strpos.cend());
			return (*iter);
		}
	};


	using ConstructorID = uint32_t;

	struct ConstructorArrays
	{
		struct
		{
			using StrPos = uint32_t;
			std::vector<char>	pool;	// e.g. "_0\0_1\0C_2\0"
			std::vector<StrPos>	strpos;
		} constructor_names;

		struct
		{

		} constructor_arglists;

		std::vector<ClassID> owner_ids;
	};


	struct ObjectArrays
	{

	};


}


#endif // OO_DATA_H