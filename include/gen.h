#ifndef GEN
#define GEN

#include <vector>

namespace lg{

	class Gen{
		// Alias
	    public:
	    typedef int index_type;
	    typedef int size_type;

		private:
		class Coord{
			public:
			index_type x;
			index_type y;
			
			Coord(index_type, index_type);

			bool operator==(const Coord&) const;
		};

		std::vector<Coord> gen;

		// Métodos
		public:
		// Construtores
		Gen();

		~Gen();

		void add(index_type i, index_type j);

		size_type size() const;

		bool operator==(const Gen&) const;

		const Coord& operator[](index_type) const;

	};

}

#endif