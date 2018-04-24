#ifndef CELL
#define CELL

namespace lg{

	/*! @class Cell
	 *
     * @brief A class that storages and manages cells status
	*/
	
	class Cell{

		///
		/// Alias
		///

	    public:
		typedef int neighbors_type; /*!< Type of neighbors */
		typedef int& ref; /*!< Reference cell*/

		/*! @enum Cell
		 *
	     * @brief Enum cells Types (DEAD OR ALIVE).
		*/

		enum class status_type : short int { DEAD = 0, ALIVE  };
		
		///
		/// Attributes
		///

		private:
		status_type status; /*!< Type of status*/
		neighbors_type n_neighbors; /*!< Number of neighbors*/
		
		
		///
		/// Methods
		///

		public:
		/*! 
		 * @brief Cell Constructor
	 	 *
		 * Initialize this Cell with DEAD or ALIVE and number of Neighbors
		 *
		 * @param r status
		 * @param c number of neighbors
		*/
		Cell (status_type, neighbors_type);

		/*! 
		 * @brief Cell Destructor
		 *
		 * Destroys this Cell
		*/
		Cell ();

		/*! 
		 * @brief Get Status
		 *
		 * @return status 
		*/
		status_type get_status( void ) const;
		/*! 
		 * @brief Set Status
		 *
		 * @param s DEAD or ALIVE 
		*/
		void set_status( status_type );

		/*! 
		 * @brief Get Number of Neighbors
		 *
		 * @return number of neighbors 
		*/
		neighbors_type get_n_neighbors( void ) const;

		/*! 
		 * @brief Set Number of Neighbors
		 *
		 * @param n number of neighbors ALIVE
		*/
		void set_n_neighbors( neighbors_type );

	};

}

#endif