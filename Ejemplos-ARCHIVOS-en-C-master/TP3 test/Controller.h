/** \brief Carga datos al programa desde un archivo en formato texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga datos al programa desde un archivo en formato binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief agrega un nuevo empleado a la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief modifica los datos de un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief imprime la lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordena la lista de empleados segun el parametro suministrado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda una lista en un archivo formato texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief guarda una lista en un archivo en formato binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


