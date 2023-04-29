let input = prompt('Введіть елементи масиву, розділені комами:');
let arr = input.split(',').map(Number);

// Функції QuickSort, Partition, та RandomizedPartition

function QuickSort(arr, left, right) {
  if (left < right) {
    let pivotIndex = RandomizedPartition(arr, left, right);
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
  }
}

function Partition(arr, left, right) {
  let pivot = arr[right];
  let i = left - 1;
  for (let j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      let temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  let temp = arr[i + 1];
  arr[i + 1] = arr[right];
  arr[right] = temp;
  return i + 1;
}

function RandomizedPartition(arr, left, right) {
  let i = Math.floor(Math.random() * (right - left + 1)) + left;
  let temp = arr[right];
  arr[right] = arr[i];
  arr[i] = temp;
  return Partition(arr, left, right);
}

// Використання функції QuickSort для сортування масиву arr

QuickSort(arr, 0, arr.length - 1);
console.log('Відсортований масив:', arr);

// Функція для пошуку порядкової статистики
function RandomizedSelect(arr, low, high, i) {
if (low == high) {
return arr[low];
}

let p = RandomizedPartition(arr, low, high);
let k = p - low + 1;

if (i == k) {
return arr[p];
} else if (i < k) {
return RandomizedSelect(arr, low, p-1, i);
} else {
return RandomizedSelect(arr, p+1, high, i-k);
}
}

// Основна функція
function main() {
let arr = [5, 3, 8, 2, 1, 9, 4, 7, 6]; // масив даних
let n = arr.length;

// Сортування масиву
QuickSort(arr, 0, n-1);
console.log("Відсортований масив:", arr);

// Пошук максимального та мінімального значення
console.log("Мінімальне значення:", arr[0]);
console.log("Максимальне значення:", arr[n-1]);

// Пошук медіани
let median;


// function quickSort(array)
// {
// 	if( array.length <= 1)
//     {
//     	return array;
//     }
//     else
//     {
//     	let q = array[0],
//     	left = [],
//     	center = [],
//     	right = [];
//     	array.forEach( (n,index) => 
//     		{
//     			if(n > q)
//     			{
//     				right.push(n);
//     			}
//     			else if (n < q)
//     			{
//     				left.push(n);
//     			}
//     			else
//     			{
//     				center.push(n);
//     			}
//     		} 
//     	)
//     	return quickSort(left).concat(center).concat(quickSort(right));
//     }
// }