/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */


const zeroes = (r, c, matrix) => {
    for (let i = 0; i < matrix.length; i++) {
        matrix[i][c] = 0;
    }
    for (let i = 0; i < matrix[0].length; i++) {
        matrix[r][i] = 0;
    }
}


var setZeroes = function(matrix) {
    const zeroesA = [];
    for(let r=0;r<matrix.length;r++){
        for(let c=0;c<matrix[0].length;c++) if(matrix[r][c]===0) zeroesA.push([r,c]);
    }

    for(let address of zeroesA){
        let r=address[0];
        let c=address[1];
        zeroes(r,c,matrix);

    }
};

