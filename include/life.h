#ifndef LIFE
#define LIFE

#include <iostream>
#include <vector>

#include "grid.h"
#include "gen.h"

/*! @namespace lg
 *
 * @brief Scope of Life Game
*/
namespace lg{
	/*! @class Life
	 *
     * @brief A class that manages the Grid of Cells and its generations
	*/
	class Life{

		///
		/// Alias
		///

	    public:
	    typedef lg::Grid::dimension_type dimension_type; /*!< Type of dimension */
	    typedef lg::Grid grid_type;						 /*!< Type of Grid */
	    typedef lg::Cell::status_type status_type;		 /*!< Type of status of the Cells */
	    
	    typedef char char_type;	  /*!< Type of character */
	    typedef int i_cell_type;  /*!< Type of grid of initialization */
	    typedef int gen_type;	  /*!< Type of number of the generations */
		
		///
		/// Attributes
		///
		private:
		dimension_type rows;  /*!< Number of rows */
		dimension_type cols;  /*!< Number of cols */
		grid_type *grid;      /*!< Grid of Cells */
		char_type out_char;   /*!< Character of ALIVE Cells */
		gen_type gen;         /*!< Actual generation */

		std::vector<lg::Gen> generations; /*!< History of all generations */
		
		///
		/// Methods
		///
		public:

		/*! 
		 * @brief Life Constructor
	 	 *
		 * Initialize this Life alocating a Grid of Cells
		 *
		 * @param r rows
		 * @param c columns
		 * @param o character of ALIVE Cells
		*/
		Life (dimension_type, dimension_type, char_type);

		/*! 
		 * @brief Life Destructor
		 *
		 * Destroys this Life
		*/
		~Life();

		/*! 
		 * @brief Set Alive
		 *
		 * Initializates the Cells of this Grid object
		 *
		 * @param alive_value value of ALIVE Cell
		 * @param i_grid grid of initialization 
		*/
		void set_alive(i_cell_type, i_cell_type **);

		/*! 
		 * @brief Update
		 *
		 * Updates this Grid of Cells
		*/
		void update();

		/*! 
		 * @brief Save Generation
		 *
		 * Saves the actual generation in the list of generations
		*/
		void save_gen();

		/*! 
		 * @brief Is Stable
		 *
		 * Returns the first occurrence of the the actual,
		 * if exists, or -1, if not
		 *
		 * @return gen number of generation
		*/
		gen_type is_stable() const;

		/*! 
		 * @brief Is Extinct
		 *
		 * Returns if the actual generation is extinct
		 *
		 * @return gen is extinct
		*/
		bool is_extinct() const;

		/*! 
		 * @brief Operator <<
		 *
		 * Prints the last generation on the out stream
		 *
		 * @param os reference of output stream
		 * @param lf reference of Life object
		 *
		 * @return ostream output stream
		*/
		friend std::ostream& operator<<(std::ostream&, const Life&);

	};

}

#endif