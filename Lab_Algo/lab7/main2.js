let countOfNumbers = 0;
function countSort(array,maxElement)
{
  countOfNumbers=0;
  orderOfNumbers = Array(maxElement+1).fill(0)
  countOfNumbers += maxElement+1
  array.forEach( value => {
      orderOfNumbers[value]++;
      countOfNumbers++;
    } 
  );
  let index = 0;
  orderOfNumbers.forEach( (value,indexValue) => {
      for(let i = 0; i < value; i++)
      {
        array[index] = indexValue;
        orderOfNumbers[indexValue]--;
        index++;
        countOfNumbers++;
      }
    } 
  )
  return array;
}