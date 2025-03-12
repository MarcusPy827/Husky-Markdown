let qtBackend = null;

function initQtWebChannel() {
    new QWebChannel(qt.webChannelTransport, function(channel) {
        qtBackend = channel.objects.Backend;
        console.log("[INFO] Qt Backend: Initialized succeed.");

        qtBackend.onRootPathChanged.connect((info) => {
            //alert(info);
        });
    });
}

initQtWebChannel();
