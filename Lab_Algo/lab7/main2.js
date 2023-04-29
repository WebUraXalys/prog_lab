let number = prompt("Введіть числа, для сортуванням по розрядах");
let numberSplit = number.split(' ').map(Number);
console.log(numberSplit);

function radixSort(array)
{ 
  let position = Array(array.length+1).fill(0).map(value => []), 
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

radixSort(numberSplit);
document.write(numberSplit);
alert(numberSplit);
console.log(numberSplit);




























// https://www.youtube.com/watch?v=YmnI39iVnmE&t=259s