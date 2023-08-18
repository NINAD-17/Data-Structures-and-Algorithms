import fs from 'fs';
import path from 'path';
import inquirer from 'inquirer';

inquirer.prompt([
    {
        message: "Enter Directory Name: ",
        name: "Directory"
    },
    {
        message: "Enter topic of question: ",
        name: "Topic"
    },
    {
        message: "Enter any keyword related to specific question: ",
        name: "Keyword"
    }
]).then((answers) => {
    const dir = answers.Directory;
    const topic = answers.Topic;
    const keyword = answers.keyword;

    searchFilesInDirectory(dir, topic, keyword);
})

const searchFilesInDirectory = (dir, topic, keyword) => {
    const files = getFilesInDirectory(dir, topic);

    files.forEach(file => {
        const fileContent = fs.readFileSync(file);

        if (fileContent.includes(keyword)) {
            console.log(`Your keyword was found in file: ${file}`);
        }
    });
}

const getFilesInDirectory = (dir, topic) => {
    let files = [];

    fs.readdirSync(dir).forEach(file => {
        const filePath = path.join(dir, file);
        const stat = fs.lstatSync(filePath);

        if (stat.isDirectory() && file === topic) {
            const nestedFiles = getFilesInDirectory(filePath, topic);
            files = files.concat(nestedFiles);
        } else if (stat.isFile()) {
            files.push(filePath);
        }
    });

    return files;
}

// searchFilesInDirectory("Arrays", "Array_Sum", "Swap");