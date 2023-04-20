function quickSort(array)
{
	if( array.length <= 1)
    {
    	return array;
    }
    else
    {
    	let q = array[0],
    	left = [],
    	center = [],
    	right = [];
    	array.forEach( (n,index) => 
    		{
    			if(n > q)
    			{
    				right.push(n);
    			}
    			else if (n < q)
    			{
    				left.push(n);
    			}
    			else
    			{
    				center.push(n);
    			}
    		} 
    	)
    	return quickSort(left).concat(center).concat(quickSort(right));
    }
}
console.log(array);
.log();