// дополнительный класс для хранения информации узла
class BinaryTreeItem {
  constructor(itemValue) {
    this.value = itemValue;
    this.left = null;
    this.right = null;
  }
}

const elementExistMessage =
  "The element has already in the tree";

class BinaryTree {
  // в начале работы дерево пустое, root отсутствует
  constructor() {
    this.root = null;
  }

  insertItem(newItem) {
    // создание нового узла дерева
    const newNode = new BinaryTreeItem(newItem);

    // проверка на пустой root, если пустой, то заполняем
    // и завершаем работу
    if (this.root === null) {
      this.root = newNode;
      return;
    }

    // вызов рекурсивного добавления узла
    this._insertItem(this.root, newNode);
  }

  _insertItem(currentNode, newNode) {
    // если значение в добавляемом узле
    // меньше текущего рассматриваемого узла
    if (newNode.value < currentNode.value) {
      // если меньше и левое поддерево отсутствует
      // то добавляем
      if (currentNode.left === null) {
        currentNode.left = newNode;
      } else {
        // если левое поддерево существует,
        // то вызываем для этого поддерева
        // процедуру добавления нового узла
        this._insertItem(currentNode.left, newNode);
      }
    }

    // для правого поддерева алгоритм аналогичен
    // работе с левым поддеревом, кроме операции сравнения
    if (newNode.value > currentNode.value) {
      if (currentNode.right === null) {
        currentNode.right = newNode;
      } else {
        this._insertItem(currentNode.right, newNode);
      }
    }

    // если элемент равен текущему элементу,
    // то можно реагировать по разному, например просто
    // вывести предупреждение
    // возможно стоит добавить проверку на NaN,
    // зависит от потребностей пользователей класса
    if (newNode.value === currentNode.value) {
      console.warn(elementExistMessage);
    }
  }
}

const binaryTree = new BinaryTree();

binaryTree.insertItem(3);
binaryTree.insertItem(1);
binaryTree.insertItem(6);
binaryTree.insertItem(4);
binaryTree.insertItem(8);
binaryTree.insertItem(-1);
binaryTree.insertItem(3.5);
console.log(binaryTree);

