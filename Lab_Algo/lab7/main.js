let numder = prompt("Введіть числа");
let numderSplit = numder.split(' ').map(Number);
console.log(numderSplit);

function radixSort(array)
{ 
  let position = Array(10).fill(0).map(value => []), 
      multiplier = 1,
      maxValue = Math.max(...array);
  while(maxValue-multiplier>=0)
  {
    array.forEach( value => {
        let slice = Math.floor(value/multiplier);
        position[slice % 10].push(value);
      } 
    )
    let indexValue = 0;
    position.forEach( values => {        
        for(let i = 0; values.length > 0; i++){
            array[indexValue] = values.shift(0);
            indexValue++;
          } 
      } 
    )
    multiplier*=10;
  }
  return array;
}

radixSort(numderSplit)

document.write(numderSplit);
alert(numderSplit);
console.log(numderSplit);