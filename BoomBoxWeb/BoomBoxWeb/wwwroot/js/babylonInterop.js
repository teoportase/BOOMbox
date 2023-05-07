var babylonInterop = babylonInterop || {};
var scene;

//TODO: REFACTOR

babylonInterop.initCanvas = function (canvasID) {
    var babylonCanvas = document.getElementById(canvasID);
    var babylonEngine = new BABYLON.Engine(babylonCanvas, true);
    scene = babylonInterop.createKirbyScene(babylonEngine, babylonCanvas);

    babylonEngine.runRenderLoop(function () {
        scene.render();
    });

    window.addEventListener("resize", function () {
        babylonEngine.resize();
    });
};

babylonInterop.createKirbyScene = function (engine, canvas) {
    console.log("Hi there");
    var scene = new BABYLON.Scene(engine);
    scene.clearColor = new BABYLON.Color4(0.5, 0.8, 0.5); // Set scene color

    var camera = new BABYLON.ArcRotateCamera("Camera", -Math.PI / 2, Math.PI / 2.5, 8, new BABYLON.Vector3(0, 0, 0), scene);
    camera.useAutoRotationBehavior = true;
    // camera.attachControl(canvas, true);

    var light1 = new BABYLON.HemisphericLight("light", new BABYLON.Vector3(0, 1, 0), scene);

    // I tried putting the model in a different directory but it didn't work
    var kirby = BABYLON.SceneLoader.ImportMeshAsync("", "../assets/", "Kirby.glb", scene);

    // A simple box model that we can load since the kirby might be a bit too heavy
    //  var box = BABYLON.MeshBuilder.CreateBox("box", {}, scene);

    return scene;
};

babylonInterop.updateCameraSpeed = function (cameraSpeed) {

    var parsedSpeed = parseFloat(cameraSpeed);
    var camera = scene.getCameraByName("Camera");
    camera.useAutoRotationBehavior = true;

    if (isNaN(parseFloat(parsedSpeed))) {
        console.log('cameraSpeed is not a valid number');
        camera.autoRotationBehavior.idleRotationSpeed = 0;
        return;
    }

    console.log('Interop.js: ' + parsedSpeed);
    camera.autoRotationBehavior.idleRotationSpeed = parsedSpeed;
};