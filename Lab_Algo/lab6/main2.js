function QuickSort(arr, left, right) {
  if (left < right) {
    let pivotIndex = RandomizedPartition(arr, left, right);
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
  }
}

// Функція для розділення масиву для швидкого сортування
function Partition(arr, left, right) {
  let pivot = arr[right];
  let i = left - 1;
  for (let j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }
  [arr[i + 1], arr[right]] = [arr[right], arr[i + 1]];
  return i + 1;
}

// Функція для випадкового розділення масиву для швидкого сортування
function RandomizedPartition(arr, left, right) {
  let i = Math.floor(Math.random() * (right - left + 1)) + left;
  [arr[right], arr[i]] = [arr[i], arr[right]];
  return Partition(arr, left, right);
}


// Частина 2. Порядкові статистики

// Функція для пошуку порядкових статистик
function RandomizedSelect(arr, left, right, i) {
  if (left === right) {
    return arr[left];
  }
  let pivotIndex = RandomizedPartition(arr, left, right);
  let k = pivotIndex - left + 1;
  if (i === k) {
    return arr[pivotIndex];
  } else if (i < k) {
    return RandomizedSelect(arr, left, pivotIndex - 1, i);
  } else {
    return RandomizedSelect(arr, pivotIndex + 1, right, i - k);
  }
}


// Функція для виведення результатів сортування та пошуку порядкових статистик
function displayResults(arr) {
  console.log(`Вихідний масив: ${arr}`);

  // Використовуємо QuickSort для сортування масиву
  QuickSort(arr, 0, arr.length - 1);
  console.log(`Відсортований масив: ${arr}`);

  // Знаходимо максимальне та мінімальне значення
  console.log(`Максимальне значення: ${arr[arr.length - 1]}`);
  console.log(`Мінімальне значення: ${arr[0]}`);

  // Знаходимо медіану
  let median;
  const mid = Math.floor(arr.length / 2);
  if (arr.length % 2 === 0) {
    median = (arr[mid - 1] + arr[mid]) / 2;
  } else {
    median = arr[mid];
  }
  console.log(`Значення Медіани: ${median}`);

  document.write(`Вихідний масив: ${arr}`);
  document.write("<br>");
  document.write(`Відсортований масив: ${arr}`);
  document.write("<br>");
  document.write(`Максимальне значення: ${arr[arr.length - 1]}`);
  document.write("<br>");
  document.write(`Мінімальне значення: ${arr[0]}`);
  document.write("<br>");
  document.write(`Значення медіани: ${median}`);
  document.write("<br>");
}

const arr = prompt("Введіть масив чисел через пробіл: ").split(" ").map(Number);

displayResults(arr);