// MQTT topic
var topic = '#temperature';

// Getting a reply from Reply handler 
// To be changed when implementing the game
function getReply() {
    $.ajax({
        type: "GET",
        url: '/?handler=Reply',
        data: "{}",
        contentType: "application/json; charset=utf-8",
        dataType: "json",
        cache: false,
        success: function (result) {
            $(topic).text(result);
        }
    });
}

/* We're not using this function for now, but I'll leave it here in case we want to display the time somewhere

function refreshServerTime() {
    var timeSpan = document.getElementById('time');
    var now = new Date();
    timeSpan.innerText = now.toLocaleString();
} 

setInterval(refreshServerTime, 1000);
*/

//Interval for recieving MQTT data
setInterval(getReply, 1000);
