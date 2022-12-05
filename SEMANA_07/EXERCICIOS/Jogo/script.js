const wordE1 = document.getElementById('word');
const wrongLettersE1 = document.getElementById('wrong-letters');
const playAgainBtn = document.getElementById('play-button');
const popup = document.getElementById('popup-container');
const popupBegin = document.getElementById('popup-begin');
const notification = document.getElementById('notification-container');
const finalMessage = document.getElementById('final-message');
const startGame = document.getElementById('beginGamePhrase');
const figureParts= document.querySelectorAll(".figure-part");



const words = ['naruto', 'chave', 'machado', 'aeroporto', 'oculos', 'garrafa', 'agenda', 'cama', 'armario', 'tela', 'cadeira', ' irmao', 'mesa' ,'folha', 'jardim', 'casaco'];

let selectedWord = words[Math.floor(Math.random() * words.length)];

const correctLetters = [];
const wrongLetters = [];







//Mostra a palavra 
function displayWord(){
    wordE1.innerHTML = `
    ${selectedWord
    .split('')
    .map(
        letter =>`
        <span class="letter">
        ${correctLetters.includes(letter) ? letter : ''}
        </span>
        `
    )
    .join('')}
    `;

    const innerWord = wordE1.innerText.replace(/\n/g, '');

    //Checa se ganhou
    if(innerWord === selectedWord){
        finalMessage.innerText = 'Parabéns você ganhou ';
        popup.style.display= 'flex';

        //Envia que ganhou para o servidor 
        $.post("/win", 
        { name: "Win"}, function(data) {
        console.log(data);
        alert(data);
    })
      
    }
}


function updateWrongLetterE1(){
    //Mostra as letras erradas 
    wrongLettersE1.innerHTML = `
    ${wrongLetters.length > 0 ? '<p>Você já errou as seguintes letras</p>' : ''}
    ${wrongLetters.map(letter => `<span>${letter}</span>`)}
    `;

    
    figureParts.forEach((part,index) => {
        const errors = wrongLetters.length;

        if(index < errors) {
            part.style.display = 'block'
        }
        else{
            part.style.display = 'none';
        }
    });

    //Checa se perdeu 
    if(wrongLetters.length === figureParts.length){
        finalMessage.innerText = 'Você perdeu ';
        popup.style.display = 'flex';
        //Envia que perdeu para o servidor
        $.post("/lost", 
        { name: "Lost"}, function(data) {
        console.log(data);
        alert(data);
    })
    }
}

//Mostra a notificação 
function showNotification(){
    notification.classList.add('show');

    setTimeout(() => {
        notification.classList.remove('show');
    }, 2000);
}

//Anotar quais letras do teclado foram apertadas 
window.addEventListener('keydown', e =>{
    if(e.keyCode >= 65 && e.keyCode <=90){
        const letter = e.key;

        if(selectedWord.includes(letter)){
            if(!correctLetters.includes(letter)){
                correctLetters.push(letter);
                displayWord();
            } else{
                showNotification();
            }
        } else{
            if(!wrongLetters.includes(letter)){
                wrongLetters.push(letter);

                updateWrongLetterE1();
            } else{
                showNotification();
            }
        }
    }
});

//Reinicia o jogo
playAgainBtn.addEventListener('click', () => {
    //Limpa as arrays 
    correctLetters.splice(0);
    wrongLetters.splice(0);

    selectedWord = words[Math.floor(Math.random() * words.length)];

    displayWord();

    updateWrongLetterE1();

    popup.style.display = 'none';
});

displayWord();
