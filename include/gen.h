#ifndef GEN
#define GEN

#include <vector>

namespace lg{

	/*! @class Generations
	 *
     * @brief A class that storages and manages generations status
	*/	

	class Gen{
		///
		/// Alias
		///
	    public:
	    typedef int index_type; /*!< Type of index */
	    typedef int size_type; /*!< Type of size */

		private:
		/*! @class Coordinates
	 	*
    	* @brief A class that represents a coordinate
		*/	
		class Coord{
			public:
			index_type x; /*!< x of coordinate */
			index_type y; /*!< y of coordinate */
			 /*! 
			 * @brief Coordinate Constructor
		 	 *
			 * Set a coordinate of ALIVE cell
			 *
			 * @param r status
			 * @param c number of neighbors
			*/
			Coord(index_type, index_type);
			/*! 
			 * @brief '==' Overload
		 	 *
			 * Overload '==' operator to verify if a coordinate is equal
			 *
			 * @param rhs coordinate of a cell
			 *
			 * @return true if this coordinate is equal
			*/
			bool operator==(const Coord&) const;
		};

		std::vector<Coord> gen; /*!< Vector of coordinates */

		
		///
		/// Methods
		///

		public:
		/*! 
		 * @brief Add
		 *
		 * Add a coordinate in a vector 
		 *
		 * @param i coordinate x
		 * @param j coordinate j
		 *
		*/	
		void add(index_type i, index_type j);
		/*! 
		 * @brief Size
		 *
		 * Return the size of vector os coordinates 
		 *
		 * @return size of vector os coordinates 
		 *
		*/	
		size_type size() const;
			/*! 
			 * @brief '==' Overload
		 	 *
			 * Overload '==' operator to verify if a generation is stable
			 *
			 * @param rhs type generation
			 *
			 * @return true if this generation is equal rhs
			*/
		bool operator==(const Gen&) const;
			/*! 
			 * @brief '[]' Overload
		 	 *
			 * Overload '[]' operator to take a element in vector of coordinates
			 *
			 * @param i index of you want
			 *
			 * @return the element in index of vector
			*/
		const Coord& operator[](index_type) const;

	};

}

#endif