let array = [9, 7, 6, 5, 4];
function mergeSort(array)
{
	if (array.length>1)
	{
		let mid = Math.floor(array.length/2),
		lefthalf = array.slice(0,mid),
		righthalf = array.slice(mid);
		mergeSort(lefthalf)
		mergeSort(righthalf)

		let i = j = k = 0
		while (i<lefthalf.length && j<righthalf.length)
		{
			if (lefthalf[i]<righthalf[j])
			{
				array[k]=lefthalf[i]
				i++;
			}
			else
			{
				array[k]=righthalf[j]
				j++
			}
			k++
		}
		while (i<lefthalf.length)
		{
			array[k]=lefthalf[i]
			i++
			k++
		}
		while( j<righthalf.length)
		{
			array[k]=righthalf[j]
			j++
			k++
		}
	}
	return array
}

mergeSort(array);

console.log(array);