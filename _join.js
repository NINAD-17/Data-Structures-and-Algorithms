const nameOfFile = "Program to add two fractions";

const filteredNameOfFile = nameOfFile.replace(/[-+(),."';:]/g, '');
const separateWords = filteredNameOfFile.split(" ");
const joinWords = separateWords.join("_");

console.log(joinWords);