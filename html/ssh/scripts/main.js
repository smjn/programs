$(document).ready(function() {
    $('#terminal').fadeIn(1500);
    var socket = io.connect('http://localhost:8001');
    socket.on('output', function(data) {
		data = data.replace(/\\n/g,'\n');
		data = data.replace(/\\r/g,'\n');
		data = data.replace('\n','<br/>');
        $('#terminal').append(data);
        $('#terminal').animate({
            scrollTop: $('#terminal').get(0).scrollHeight
        }, 200);
    });

    socket.on('err', function(err) {
        alert(err);
    });
    $('#command').on('keypress', function(e) {
        if (e.keyCode === 13) {
            e.preventDefault();
            var cmd = $('#command').text()+'\r';
            socket.emit('input', cmd);
            $('#command').text('');
        }
    });

});
