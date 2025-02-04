const nameOfFile = "Merge Sort in Linked List";

const filteredNameOfFile = nameOfFile.replace(/[-+(),."';:]/g, '');
const separateWords = filteredNameOfFile.split(" ");
const joinWords = separateWords.join("_").toLowerCase();

console.log(joinWords);