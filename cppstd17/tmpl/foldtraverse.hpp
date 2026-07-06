
// define binary tree structure and traverse helpers:
/**
* @brief Nodo de un árbol binario.
*/
struct Node
{
  /// Valor almacenado en el nodo.
  int value;
  /// Hijo izquierdo.
  Node* subLeft{nullptr};
  /// Hijo derecho.
  Node* subRight{nullptr};
  /**
  * @brief Construye un nodo.
  * @param i Valor inicial.
  */
  Node(int i = 0) : value{i} {}
  /**
  * @brief Obtiene el valor del nodo.
  * @return Valor almacenado.
  */
  int getValue() const {  return value;  }

  // traverse helpers:
  // pointer to member
  /**
  * @brief Puntero al miembro `subLeft`.
  *
  * Utilizado por `traverse()` para realizar recorridos mediante
  * el operador `->*`.
  */
  static constexpr auto left  = &Node::subLeft;
  /**
  * @brief Puntero al miembro `subRight`.
  *
  * Utilizado por `traverse()` para realizar recorridos mediante
  * el operador `->*`.
  */
  static constexpr auto right = &Node::subRight;

  // traverse tree, using fold expression:
  //expansion
  /**
  * @brief Recorre el árbol siguiendo una secuencia de punteros a miembros.
  *
  * Implementado mediante una fold expression sobre el operador `->*`.
  *
  * Ejemplo:
  * @code
  * Node::traverse(root, Node::left, Node::right);
  * // Equivale a:
  * // root->subLeft->subRight
  * @endcode
  *
  * @tparam T Tipo del nodo inicial.
  * @tparam TP Secuencia de punteros a miembros.
  * @param np Nodo inicial.
  * @param paths Ruta a recorrer.
  * @return Nodo alcanzado tras aplicar la secuencia de accesos.
  */
  template<typename T, typename... TP>
  static Node* traverse (T np, TP... paths)
  {
    return (np ->* ... ->* paths);      // np ->* paths1 ->* paths2 ...
  }
};

