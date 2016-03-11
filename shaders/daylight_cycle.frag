uniform sampler2D texture;
uniform float time;

void main() {
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    
    vec4 blend = vec4(1, 1, 1, 1);
    float f = 0;
    if (time >= 5.0 && time < 6.0) {
      f = (time - 5.0) / 1.0;
      blend = vec4(0.2, 0.2, 0.8, 1) * (1.0 - f) + vec4(0.75, 0.5, 0.75, 1) * (f);
    } else if (time >= 6.0 && time < 8.0) {
      f = (time - 6.0) / 2.0;
      blend = vec4(0.75, 0.5, 0.75, 1) * (1.0 - f) + vec4(1, 1, 1, 1) * (f);
    } else if (time >= 18.0 && time < 20.0) {
      f = (time - 18.0) / 2.0;
      blend = vec4(1, 1, 1, 1) * (1.0 - f) + vec4(0.75, 0.3, 0.3, 1) * (f);
    } else if (time >= 20.0 && time < 21.0) {
      f = (time - 20.0) / 1.0;
      blend = vec4(0.75, 0.3, 0.3, 1) * (1.0 - f) + vec4(0.2, 0.2, 0.8, 1) * (f);
    } else if (time >= 21 || time < 5.0) {
      blend = vec4(0.2, 0.2, 0.8, 1);
    }

    gl_FragColor = gl_Color * pixel * blend;
}