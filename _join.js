const nameOfFile = "Rotate a Matrix by 90 degrees";

const filteredNameOfFile = nameOfFile.replace(/[-+(),."';:]/g, '');
const separateWords = filteredNameOfFile.split(" ");
const joinWords = separateWords.join("_");

console.log(joinWords);