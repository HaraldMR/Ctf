function setupPlayer(audioElementId, playlistElementId) {
    var audio = document.getElementById(audioElementId);
    var playlist = document.getElementById(playlistElementId);
    var tracks = playlist.getElementsByTagName('a');
    var currentTrack = 0;

    function playTrack(e) {
        e.preventDefault();
        var selectedTrack = this.getAttribute('href');
        audio.src = selectedTrack;
        audio.play();

        for (var j = 0; j < tracks.length; j++) {
            tracks[j].parentNode.classList.remove('active');
        }
        this.parentNode.classList.add('active');
    }

    for (var i = 0; i < tracks.length; i++) {
        if (tracks[i].parentNode.classList.contains('active')) {
            currentTrack = i; // Update currentTrack to the index of the active element
            audio.src = tracks[i].getAttribute('href'); // Set the audio source to the active track
        }
        tracks[i].addEventListener('click', playTrack, false);
    }

    audio.addEventListener('ended', function() {
        currentTrack++;
        if (currentTrack >= tracks.length) {
            currentTrack = 0;
        }
        tracks[currentTrack].click();
    });
}

window.onload = function() {
    setupPlayer('audio1', 'playlist1');
    setupPlayer('audio2', 'playlist2');
}