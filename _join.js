const nameOfFile = "All divisors of a natural number";

const filteredNameOfFile = nameOfFile.replace(/[-+(),."';:]/g, '');
const separateWords = filteredNameOfFile.split(" ");
const joinWords = separateWords.join("_");

console.log(joinWords);