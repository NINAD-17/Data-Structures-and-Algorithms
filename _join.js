const nameOfFile = "Check if Array Is Sorted and Rotated";

const filteredNameOfFile = nameOfFile.replace(/[-+(),."';:]/g, '');
const separateWords = filteredNameOfFile.split(" ");
const joinWords = separateWords.join("_");

console.log(joinWords);