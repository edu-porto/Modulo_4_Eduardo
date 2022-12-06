/////////////////////////////////////////////////////////////////////////////
//////////////////// CÓDIGO FIREBASE 



//Inicializando o firebase 
const firebaseConfig = {
    apiKey: "AIzaSyBGxOrXcXZ4pH42Weyum2ek9tWVztP0WyE",
    authDomain: "crudjsfb-d5cb2.firebaseapp.com",
    databaseURL: "https://crudjsfb-d5cb2-default-rtdb.firebaseio.com",
    projectId: "crudjsfb-d5cb2",
    storageBucket: "crudjsfb-d5cb2.appspot.com",
    messagingSenderId: "26388105663",
    appId: "1:26388105663:web:8f28de293c19dcdaaf790a"
  };
firebase.initializeApp(firebaseConfig);




//Definindo um nome para a linha no firebase
var messagesRef = firebase.database().ref('Data')
 


//Função post do estado quando o jogador perde 
function lostMessage() {
    messagesRef.set({
        estate: 0,
    });
}

//Função post do estado quando o jogador ganha 
function winMessage() {
    messagesRef.set({
        estate: 1,
    });
}

//Função post do estado quando o jogo reinicia  
function restartMessage() {
    messagesRef.set({
        estate: 3,
    });
}


////////////////////////////////////////////////////////////////////////////////////////
// CÓDIGO DO JOGO
const wordE1 = document.getElementById('word');
const wrongLettersE1 = document.getElementById('wrong-letters');
const playAgainBtn = document.getElementById('play-button');
const popup = document.getElementById('popup-container');
const popupBegin = document.getElementById('popup-begin');
const notification = document.getElementById('notification-container');
const finalMessage = document.getElementById('final-message');
const startGame = document.getElementById('beginGamePhrase');
const figureParts= document.querySelectorAll(".figure-part");


//Pegando os dados da outra página em formato JSON
const myObjectString2 = localStorage.getItem('objectGreeting');
const myObject2 = JSON.parse(myObjectString2);

//Transformando JSON em array para enviar par o jogo
var wordConverted = []
for (var x in myObject2) {
    wordConverted.push([x, myObject2[x]])
}
//Removendo o primeiro elemento da array pois é a classificação do JSON
var flatArray = wordConverted.flat()
console.log(flatArray[1]);  


//Definindo o elemento 1 da array como a palavra a ser adivinhada pelo outro player
let selectedWord = flatArray[1]

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
        winMessage()
      
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
        lostMessage()
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

    restartMessage()

    displayWord();

    updateWrongLetterE1();

    popup.style.display = 'none';


});

displayWord();
