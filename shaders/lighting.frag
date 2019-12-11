uniform sampler2D texture;
uniform sampler2D daylight;
uniform float time;

void main() {
    gl_FragColor = texture2D(texture, gl_TexCoord[0].xy) * texture2D(daylight, vec2(time, 0));
}