
attribute vec3 aPositionCoordinates;
attribute vec3 aNormalCoordinates;

varying vec3 vColorValues;

void main()
{
    vColorValues = aNormalCoordinates;
    
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPositionCoordinates, 1);
}