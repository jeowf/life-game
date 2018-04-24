#ifndef GRID
#define GRID

#include "cell.h"

namespace lg{
	/*! @class Grid
	 *
     * @brief A class that storages and operates a matrix of Cells
	*/
	class Grid{

		///
		/// Alias
		///

	    public:
		typedef long int dimension_type; 			/*!< Type of dimension */
		typedef lg::Cell cell_type;					/*!< Type of Cell */
		typedef lg::Cell::status_type status_type;  /*!< Type of status of the Cells */
		typedef int i_cell_type;					/*!< Type of grid of initialization */
		typedef int index_type;						/*!< Type of index in Grid */
		
		///
		/// Attributes
		///

		private:
		dimension_type n_rows;		/*!< Number of rows */
		dimension_type n_columns;	/*!< Number of columns */
		cell_type **grid;			/*!< Matrix of Cells */
		
		
		///
		/// Methods
		///

		public:

		/*! 
		 * @brief Grid Constructor
	 	 *
		 * Initialize this Grid with DEAD Cells
		 *
		 * @param r rows
		 * @param c columns
		*/
		Grid (dimension_type, dimension_type);

		/*! 
		 * @brief Grid Destructor
		 *
		 * Destroys this Grid
		*/
		~Grid ();

		/*! 
		 * @brief At
		 *
		 * Get the Cell at specified coordinate in this Grid 
		 *
		 * @param x row
		 * @param y column
		 *
		 * @return cell cell at (x,y)
		*/
		cell_type& at(index_type, index_type);


		/*! 
		 * @brief Calculate Neighbors
		 *
		 * Calculate the number of ALIVE neighbors in this Grid
		*/
		void calculate_neighbors();

		/*! 
		 * @brief Reset Neighbors
		 *
		 * Reset the number of neighbors of all Cells in this Grid
		*/
		void reset_neighbors();

		/*! 
		 * @brief Next Generation
		 *
		 * Generate the next generation based on rules B3/S23
		*/
		void next_gen();

		private:
		/*! 
		 * @brief Wrap Index
		 *
		 * Return a wrapped index in this Grid
		 *
		 * @param v index
		 * @param i_min minumum index
		 * @param i_max maximum index
		 *
		 * @return w wrapped index
		*/
		index_type wrap_index(index_type, index_type, index_type);

	};

}

#endif