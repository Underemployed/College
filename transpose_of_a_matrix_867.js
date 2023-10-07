/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    for(let r=0;r<matrix.length;r++){
        for(let c=r;c<matrix[0].length; c++){
            if(c==r) continue;
            [matrix[r][c],matrix[c][r]]=[matrix[c][r],matrix[r,c]];
    }}
    for(let row of matrix){
        row.reverse();
    }
    return matrix;
};