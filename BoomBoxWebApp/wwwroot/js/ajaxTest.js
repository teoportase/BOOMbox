var chart;
var ctx;
var count = 0;

document.addEventListener('DOMContentLoaded', function () {
    ctx = document.getElementById('tempChart').getContext('2d');
    chart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: [], // x-axis (labels)
            datasets: [{
                label: 'Temperature',
                data: [], // y-axis (values)
                fill: false,
                borderColor: 'rgb(75, 192, 192)',
                tension: 0.1
            }]
        },
        options: {}
    });
})



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

            //Updating the chart
            chart.data.labels.push(count);
            chart.data.datasets[0].data.push(parseFloat(result.substring(0, 5).replace(',', '.'))); //Specific to the temperature
            chart.update();
            count++;
        }
    });
}

function refreshServerTime() {
    var timeSpan = document.getElementById('time');
    var now = new Date();
    timeSpan.innerText = now.toLocaleString();
}

//Interval for recieving MQTT data
setInterval(getReply, 1000);

//Interval for refreshing server time
setInterval(refreshServerTime, 1000);