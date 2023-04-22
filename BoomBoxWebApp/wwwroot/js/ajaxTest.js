function getReply() {
    $.ajax({
        type: "GET",
        url: '/?handler=Reply',
        data: "{}",
        contentType: "application/json; charset=utf-8",
        dataType: "json",
        cache: false,
        success: function (result) {
            $('#temperature').text(result);
        }
    });
}

function refreshServerTime() {
    var timeSpan = document.getElementById('time');
    var now = new Date();
    timeSpan.innerText = now.toLocaleString();
}

setInterval(getReply, 1000);
setInterval(refreshServerTime, 1000);